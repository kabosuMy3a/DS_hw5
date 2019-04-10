#ifndef __STACK_H__
#define __STACK_H__

typedef char* Element ;


class Stack{


	private : 

		int top;
		int max_size;
		Element * box; 

	public :


		Stack();
		Stack(int max_num);
		~Stack();
		bool IsFull() const;
		bool IsEmpty() const;
		void Push(Element item);
		Element Pop();
		void Print(int top);
		int getTop();  
		int getMax();










};

#endif
