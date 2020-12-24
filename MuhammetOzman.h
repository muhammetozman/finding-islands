#include <iostream>
#include <cstring>
#include <queue>
#include<stdlib.h>
using namespace std;
	
namespace MuhammetOzman{

	int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
	int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };
	
	class MapInterface {
		
		
		public:	
	
			virtual ~MapInterface() {}	
			// Creates a map of given size.
			virtual void SetSize(const int width, const int height) = 0;
			// Returns size of map to solve.
			virtual void GetSize(int & width, int & height) = 0;
			// Sets border at given point.
			virtual void SetBorder(const int x, const int y) = 0 ;
			// Clears border at given point.
			virtual void ClearBorder(const int x, const int y) = 0;
			// Checks if there is a border at given point.
			virtual bool IsBorder(const int x, const int y) = 0;
			// Show map contents.
			virtual void Show() = 0;
	};
	
	class ZoneCounterInterface {
		public:
			virtual ~ZoneCounterInterface() {}
			// Feeds map instance into solution class, and initialize.
	//		virtual void Init(MapInterface * map) = 0;
			// Counts zones in provided map, and return result.
			virtual int Solve() = 0;
	};
	
	
	class MyMap : public MapInterface{
		
		public:
		int h, w;	 
			//size components of map
			int ** matris;	//map
			
			MyMap(int r, int c){
				h=r; 
				w=c;
				matris= new int*[r];
				//create dynamic matris and initialize map
				for(  int i = 0; i < r; i++ ) {
					matris[i]= new int [c];
				}
				cout<<"Mapp is created."<<endl;
			}
			
			~MyMap(){
							
				for(  int i = 0; i < h; i++ ) {
					delete[] matris[i];
				}
				delete[] matris;
				cout << "map is deleted";	
			}
			
			void SetSize(const int width, const int height){
				
				//assume all map is zone and initialize with zone points equals 1
				for( int i = 0; i < height; i++ ) {
					for( int j = 0; j < width; j++ ) {
						matris[ i ][ j ] = 1;
					}
				}
				cout<<"Height of this map "<<height<<endl;
				cout<<"Width of this map "<<width<<endl;
			}
			
			void GetSize(int & width, int & height){
				cout<<"Height of this map "<<h<<endl;
				cout<<"Width of this map "<<w<<endl;
			}	
			
			void SetBorder(const int x, const int y) {
				//Assigning 0 to border points.
				matris[ x ][ y ] = 0;
			}
			
			void ClearBorder(const int x, const int y){
				//Assigning 1 to zone points.
				matris[ x ][ y ] =1;
			}
		
			bool IsBorder(const int x, const int y){
				if(matris[x][y]==1){
		        	cout<< "This coordinate point is the border"<<endl;
		    		return true;    
				}
				else{
		        	cout<< "This coordinate point is not the border"<<endl;
		    		return false; 		
				}
	
		}
	
		void Show(){
			//Show map contents
			for(int i = 0; i < h; i ++) {
		
		        for(int j = 0; j < w; j ++){
		          	cout<< matris[i][j]; // let the boundaries denote by 0.
				}           
		        cout<<endl;
		    }
		    cout<<endl;
	
		
		}
	};
	
	class MyZone : public ZoneCounterInterface{
		int M,N;
		int ** mat;
		public:

			MyMap *mapp;
			MyZone(MyMap * map){
			mapp=map;	

			}			
			void Init(MyMap * map) {
				mat=mapp->matris;
				M=sizeof(mat) / sizeof(mat[0]);
				N=sizeof(mat[0])/sizeof(mat[0][0]);
				cout<<M;
				cout<<N;
			}

			int Solve() {
			 	int M= mapp->h; 
			 	int N= mapp->w;
				int ** mat=mapp->matris;
			// stores if cell is processed or not
			bool processed[M][N];
			// mark all cells as unprocessed
			memset(processed, 0, sizeof(processed));
		
			int zone = 0;
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
			
					// increment zone count
					if (mat[i][j] && processed[i][j] == 0)
					{
			// create an empty queue and enqueue source node
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
		
			// mark source node as processed
			processed[i][j] = true;
		
			 // loop till queue is empty
			while (!q.empty())
			{
				// pop front node from queue and process it
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
		
				// check for all 8 possible movements from current cell
				// and enqueue each valid movement
				for (int k = 0; k < 8; k++)
				{
					// skip if location is invalid or it is already
					// processed or consists of water
					if ((x  + row[k] >= 0) && (x + row[k] < M) && (y + col[k] >= 0) && (y + col[k] < N) &&
				(mat[x + row[k]][y + col[k]] && !processed[x + row[k]][y + col[k]]))
					{
						// mark it processed & push it into the queue
						processed[x + row[k]][y + col[k]] = 1;
						q.push(make_pair(x + row[k], y + col[k]));
					}
				}
			}
						zone++;
					}
				}
			}
		
			cout << "Number of zones are " << zone << '\n';
				
				}
		};
	
}

		
		
		
		
		

