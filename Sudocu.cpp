#include<iostream>

#include<cstdlib>

#include<ctime>

using namespace std ;

const int Col=10;

void Initialize0(int M[][Col], int n, int m) ;

void printMatrix(int M[][Col], int n, int m);

bool CheckSum(int M[][Col], int n, int m) ;

bool CheckElementsInRow(int M[][Col], int n, int m, int row)  ;

bool CheckElementsInColumn(int M[][Col], int n, int m, int column) ;

bool CheckElementsInSubMatrix(int M[][Col], int n, int m, int subN, int subM) ;

void initSpace1(int M[][Col], int n=9, int m=9) ;


int main () {
	std::srand(static_cast<unsigned>(std::time(0)));
	int M[10][10];
	int submatrix;
	int column;
	int row;
	int value;
	int tries;
	int counter = 0;
	tries = 3;
	cout << "       ##########  ##         ##  ####            ############  ##     ###     ##         ##\n";
	cout << "       ##########  ##         ##  ######          ############  ##   ###       ##         ##\n";
	cout << "       ##          ##         ##  ##  ####        ##        ##  ## ###         ##         ##\n";
	cout << "       ##          ##         ##  ##    ####      ##        ##  ####           ##         ##\n";
	cout << "       ##########  ##         ##  ##      ###     ##        ##  ####           ##         ##\n";
	cout << "       ##########  ##         ##  ##        ###   ##        ##  ## ###         ##         ##\n";
	cout << "               ##  ##         ##  ##         ###  ##        ##  ##   ###       ##         ##\n";
	cout << "               ##  ##         ##  ##       ###    ##        ##  ##     ###     ##         ##\n";
	cout << "       ##########  #############  ###########     ############  ##      ###    #############\n";
	cout << "       ##########  #############  #########       ############  ##       ####  #############\n";
	cout << "   " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "                      <-----------------------------THE RULES------------------------->" << endl;
	cout << "                       Each row must contain every number from 1 to 9 without repetition.                                                                  " << endl;
	cout << "                    Each column must also contain every number from 1 to 9 without repetition.                                      " << endl;
	cout << "                   Each 3x3 sub-matrix must have all the numbers from 1 to 9 without repetition.                                                                                " << endl;
	cout << "        A victory in the game is declared when the sum of each column equals the corresponding sum of the row,                                                                                 " << endl;
	cout << "                      <--------------------------- let's begin ------------------------>" << endl;

	initSpace1(M, 9, 9);


	while (true) {
         counter=0;
		printMatrix(M, 9, 9);
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
	
		cout << " <> select the column in the sudoko (1 to 9 ) : ";
		cin >> column;
		
		cout << " <> select the row in the sudoko (1 to 9) : ";
		cin >> row;
        while (row < 1 || row > 9 || column < 1 || column > 9) { 
            cout << "Invalid row/column, try again: ";
            cin >> row >> column;
         }

        //check for empty position

        	while (M[row-1][column-1] != 0) {

			cout << " <> the position you entered is not empty , try another position :" << endl;

			cout << " <> select column(1 to 9) : ";
			cin >> column;
			
			cout << " <> select row(1 to 9) : ";
			cin >> row;

            while (row < 1 || row > 9 || column < 1 || column > 9) { 

            cout << "Invalid row/column, try again: ";
            cin >> row >> column;

         }
			
            }
		
		cout << " <> enter the value you want to put in the poition you had selected : ";
		cin >> value;

		while (value < 1 || value>9) {

			cout << " <> wrong value.. try to enter another value : ";

			cin >> value;
		}
	
		M[row-1][column-1] = value;


		if (CheckElementsInRow(M, 9, 9, (row-1)) || CheckElementsInColumn(M, 9, 9, (column-1)) || CheckElementsInSubMatrix(M, 9, 9, 3, 3)) {

			M[row - 1][column - 1] = 0;

			tries--;
            
			cout << " <> mistake, you have  "<<tries<<" tries " << endl;
		}

         // if lost
		if (tries == 0) {
			cout << " <> you lose :" << endl;
			break;
		}

        //check for win

		for (int i = 0; i < 9; i++) {

			for (int j = 0; j < 9; j++) {

				if (M[i][j] != 0) {

					counter++;
				}else break ;
			}
		}
		if (counter == 81) {

			cout << " <> you win , congratulations" << endl;

			break;
		}
	}
}

void Initialize0(int M[][Col], int n, int m){
      
    for(int i=0 ; i<n ; i++){

        for(int j=0 ; j<m ; j++){

            M[i][j]=0 ;

        }
    }
}
void printMatrix(int M[][Col], int n, int m){

    for(int i=0 ; i<n ; i++){
         
        cout<<"| " ;

        for(int j=0 ; j<m ; j++){

            cout<<M[i][j]<<" | " ;            

        }
        cout<<"\n";
        for(int k=0 ; k<=(6*m)-4 ; k++){

            cout<<"-";
        }

        cout<<"\n" ;
    }
}

bool CheckSum(int M[][Col], int n,  int m) {

 int i = 1 ; int j , sum=0 , check=0 ;

   //counting the first rows's sum

   for(int k = 0 ; k<m ; k++){

    check+=M[0][k];
    
   }



    //stop when there is a non equality in rows
   while(i<n){

        j=0 ;

         while(j<m){

          sum+=M[i][j] ;
 
           j++;
        }
      
      if(sum!=check ) return false ;    

      else{
        
           i++ ;

           sum=0 ;

       }
   }
   //computing the first columns's sum

   check=0 ;

   for(int k = 0 ; k<m ; k++){

    check+=M[k][0];
    
   }
   

   j=0 ;

   i=0 ;
   
 //comparing the sum of columns with the first one

   while(i<m){

        j=0 ;

         while(j<n){

         sum+=M[j][i] ;
 
           j++;
        }
      
      if(sum!=check ) return false ;    

      else { i++ ; sum=0 ;} 

   }

   return true ;
}

bool CheckElementsInRow(int M[][Col], int n, int m, int row) {

    //iterating over each element 

    for(int i=0 ; i<n-1; i++){

        //comparing it with others
        for(int j=i+1 ; j<n ;j++){

          if(M[row][i] !=0   && M[row][j]==M[row][i] ) return true ;


        }

    }

     return false ;
}
bool CheckElementsInColumn(int M[][Col], int n, int m, int column){
     
      //iterating over each element 

    for(int i=0 ; i<m-1; i++){

        //comparing it with others
        for(int j=i+1 ; j<m ;j++){

          if(M[i][column] !=0   && M[j][column]==M[i][column] ) return true ;


        }

    }

     return false ;

}

bool CheckElementsInSubMatrix(int M[][Col], int n, int m, int subN, int subM) {
    for (int startX = 0; startX < n; startX += subN) {
        for (int startY = 0; startY < m; startY += subM) {
            int a[subM * subN] = {0}; // Initialize array with zeros
            int count = 0;

            for (int i = startX; i < startX + subN; i++) {
                for (int j = startY; j < startY + subM; j++) {
                    if (M[i][j] != 0) {
                        for (int k = 0; k < count; k++) {
                            if (a[k] == M[i][j]) {
                                
                                return true; // Found a duplicate element
                            }
                        }
                        a[count] = M[i][j];
                        count++;
                    }
                }
            }
        }
    }
    return false; // No duplicates found within submatrices
}

bool CheckAll(int M[][Col] , int n ,int m , int subN , int subM ){

    //checking all columns

  for(int j = 0 ; j<m ; j++){

       if(CheckElementsInColumn(M , n , m , j)) return false ;
  }

//checking all rows

  for(int i=0 ; i<n ; i++){

        if(CheckElementsInRow(M , n , m , i)) return false ;

  }

  //if all rows and columns are checked true then check submatrix

  if(CheckElementsInSubMatrix(M , n , m , subN , subM)) return false;

  //everything is OK
  
  else return true ;

}

void initSpace1(int M[][Col], int n, int m) {

	for (int o = 0; o < 9; o++) {

		for (int p = 0; p < 9; p++) {

			M[o][p] = 0;
		}
	}
	std::srand(static_cast<unsigned>(std::time(0)));

	int rn;

	int position[3];

	int c = 0, attempts = 0;
    

	for (int x = 0; x < 9; x++) {


		do {

			for (int i = 0; i < 3; i++) {

				position[i] = rand() % 9;
			}

		} while (position[0] ==position[1] || position[1] == position[2] || position[0] == position[2]);

		for (int d = 0; d < 3; d++) {

			do {
                attempts++;
				rn = rand() % 9 + 1;

				M[x][position[d]] = rn;

                // Note: This random initializer may loop if it cannot place numbers without conflict.
                if (attempts > 50) {
                    cout<<"Unable to initialize the grid, please try again!";   
                    break;
                }


			} while (!CheckAll(M , n , m , 3 , 3)) ;
		}
		
	}
	
}
