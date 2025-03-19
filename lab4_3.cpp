using namespace std;


struct stack_el {
	int value;
	stack_el* next;
};
struct int_list {
	stack_el* top = nullptr;
	void add_el(int el_val) {
    	stack_el* el = new stack_el{ el_val, top };
    	this->top = el;
	}
	void insert(int el_val, int index) {
    	stack_el* view_ptr = this->top;
    	for (int i = 0; i < index - 1; i++) {
        	view_ptr = view_ptr->next;
    	}
    	stack_el* el_after = view_ptr->next;
    	stack_el* el = new stack_el{ el_val, el_after };
    	view_ptr->next = el;
	}
	void rem(int index) {
    	stack_el* view_ptr = this->top;
    	for (int i = 0; i < index - 1; i++) {
        	view_ptr = view_ptr->next;
    	}

    	stack_el* to_rem = view_ptr->next;
    	view_ptr->next = to_rem->next;
    	delete to_rem;
	}
	void replace_val(int old_val, int new_val) {
    	stack_el* view_ptr = this->top;
    	while (view_ptr->next != nullptr) {
        	if (view_ptr->value == old_val) {
            	view_ptr->value = new_val;
            	return;
        	}
        	view_ptr = view_ptr->next;
    	}
	}
	bool is_empty() {
    	return this->top == nullptr;
	}
	int top_i() {
    	if (this->is_empty()) {
        	cerr << "try to top_i() an empty stack";
    	}
    	else {
        	return this->top->value;
    	}
	}
	void pop() {
    	if (this->is_empty()) {
        	cerr << "try to pop() an empty stack";
    	}
    	else {
        	stack_el* to_pop = this->top;
        	this->top = this->top->next;
        	delete to_pop;
    	}
	}
	void view() {
    	if (this->is_empty()) {
        	cout << "stack is empty";
        	return;
    	}
    	stack_el* last = this->top;
    	while (last != nullptr) {
        	cout << last->value << endl;
        	last = last->next;
    	}
    	cout << endl;
	}
	void clear() {
    	while (!this->is_empty()) {
        	this->pop();
    	}
	}
};

int main() {
	int_list list;
	int elements[5] = { 4, 3, 1, 2, 4 };
	for (int i = 0; i < 5; i++) {
    	list.add_el(elements[i]);
	}
	list.view();
	list.insert(9, 1);
	list.view();
	list.replace_val(4, 7);
	list.view();
	list.rem(2);
	list.view();
	return 0;
}
