
static struct _mydrv_wq {
	struct list_head mydrv_worklist; /* List head */
	spinlock_t lock;
	wait_queue_head_t todo; /* wait queue*/
} mydrv_wq;

struct _mydrv_work {
	struct list_head mydrv_workitem;
	void (* work_func)(void *)
	void (* workdata)
	
}mydrv_work;


int __init mydrv_init(){
	
	spin_lock_init(&mydrv_wq.lock);
	init_waitqueue_head(&mydrv_wq.todo);
	INIT_LIST_HEAD(&mydrv_wq.mydrv_worklist);
	Kernek_thread(mydrv_worker), NULL, FLAGS);	
}


int submit_work(void(*func)(void *data), void * data){
	struct _mydrv_work *mydrv_work = kmalloc(sizeof(mydrv_work),GFP_ATOMIC);
	mydrv_work->work_func = func;
	mydrv_work->data = data
	spinlock(&mydrv_wq);
	list_add_tail(&mydrv_work->mydrv_workitem, &mydrv_wq_mydrv_worklist);
	wake_up(mydrv_wq.todo);
	spin_unlock(&mydrv_wq.lock);
	return 0;
	
	
}


public 
private -> not access from the derived
protected


pointers:
	- integer which stores address
	- void* means it typeless
	- delete [] -> it is used to delete what is created by new[size]


reference:
	- int& -> that is how u declare a reference
	- int& ref = a -> it means ref and a is the the same thing 
	void function(&a){
		a++;
	} -> that is how u define a function that takes reference
	- u can make the reference which it is pointed to it	


- class:
	- it is a way to group the data 
	- by default every thing is private unless u changed it
	- method takes instance of the class as parameter

virtual:
	- it gives the ability to override a method
	- u mark the base function as virtual
	- u write the function in the derived class override

static:
	- inside a file u make it local it to the file
	- inside a class it means there is one instance in the class
	- u need to define a static member some where
	- to access them u use class::name 
	- u use it to have variables cross classes
	- static method can access only static member
	- 
enum:
- it is used to group integer 
- 