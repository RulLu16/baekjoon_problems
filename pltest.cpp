#include <stdio.h>
#include <iostream>

using namespace std;

/*class A{
	protected:
		int i, j;
		
	public:
		A(int x, int y){
			i = x; j = y;
		}
		virtual void printvar(){
			printf("%d %d\n", i, j);
		}
};

class B : public A{
	protected: int i, j;
	public:
		B(int x, int y) : A(11, 22){
			i = x; j = y;
		}
		void printvar(){
			printf("%d %d\n", i, j);
		}
};

main(){
	A a(11, 22), *pa;
	B b(33, 44), *pb;
	
	a.printvar();
	b.printvar();
	
	a = b;
	a.printvar();
	
	pa = &b;
	pa->printvar();
}

class A{
	private:
		int a;
	protected:
		int b;
	public:
		A(){
			b = a = 3;
			printf("Creating a\n");
		}
		~A(){
			printf("destory a\n");
		}
		sub1(){
			printf("a=%d\n", a);
		}
};

class B : public A{
	private:
		int c;
	public:
		B(){
			c = 4;
			//c = a;
			printf("Creating b\n");
		}
		~B(){
			printf("destory b\n");
		}
		sub1(){
			A::sub1();
			printf("b=%d, c=%d\n", b, c);
		}
};


main(){
	B b;
	b.sub1();
}*/

class B{
	public:
		B(int j=0): i(j){
		}
		virtual void print(){
			cout << "B::" << "i=" << i << endl;
		}
		void print(char* s){
			cout << "B::" << s << i << endl;
		}
		private:
			int i;
};
class D:public B{
	public:
		D(int j=0): B(5), i(j){
		}
		virtual void print(){
			cout << "A::" << "i=" << i << endl;
		}
		void print(char* s){
			cout << "A::" << s << i << endl;
		}
		private:
			int i;
};

main(){
	B b1, b2(10), *pb;
	D d1, d2(3), *pd = &d2;
	b1.print();
	d2.print("d2.i=");
	pb=pd; pb->print();
	pb->print("d2.i=");
	pd->print("d2.i=");
}
