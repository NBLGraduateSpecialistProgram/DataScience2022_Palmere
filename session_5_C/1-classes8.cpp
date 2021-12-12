#include <iostream>

class Polygon{
	
	public:
		
		int x = 0;
		int y = 0;

		Polygon(){
			std::cout << "Polygon created." << std::endl;
		}

		~Polygon(){
			std::cout << "Polygon removed." << std::endl;
		}

		void display(){ // Overload the function from the base class (not override)

            for (int i = 0; i < x; i++){
                std::cout << "-";
            }   
            std::cout << std::endl;
                
            for (int j = 0; j < y; j++){
                for (int i = 0; i < x; i++){
                    if (i == 0 || i == (x-1)){
                        std::cout << "|";
                    }   
                    else{
                        std::cout << " ";
                    }   
                }   
                std::cout << std::endl;
            }   

            for (int i = 0; i < x; i++){
                std::cout << "-";
            }   
            std::cout << std::endl;

        }   
};

class Rectangle: public Polygon {

	public: 

		Rectangle(int nx, int ny){

			x = nx;
			y = ny;

		}
};

class Square : public Polygon {

	public:

		Square(int nyx){
			x = nyx;
			y = nyx / 2; // '|' is about 2x bigger than '-'
		}

};
int main(){
	
	Rectangle A(4, 3);
	Square B(4);

	Polygon* P1 = &A;
	Polygon* P2 = &B;

	P1->display();
	P2->display();

	return 0;
}


