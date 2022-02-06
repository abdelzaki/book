
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