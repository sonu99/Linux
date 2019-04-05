1> start with notes.
Q>---> what is os.
Ans:        1> os will allocate the resource in efficient manaer, so it will helps to do multi tasking, multi processing,
            2> os will security to process
           -> each process will run at seprate virtual space.
           -> and other process can't touch it. for doing that we can use IPC.
           
Q> multi tasking, multiprocessing, multi thereading.
Ans:
          -> multi tasking:- ablity to run more than one task. (notpad and firefox)
          -> multi processing: - ablity of os to run process, on more than one core or handle or controll more than one than.
          -> multi threading:-    
Q> ---> diffrent between linux os and RTOS
Ans:               
          -> task should done at fixed time...(quality at fixed time)
          -> (focus on multitasking)
Q---> How we can make RTOS and RT linux
Ans--?
---> what is user sapce.
Ans:-
           ---> what is kernel space 
           ---> why os divided in user and kernel space.
Q---> how to jump user space to kernel space.
Ans:-
            
            
------------------------------------------------------------------Memory manager--------------------------------------------
Reference: https://www.linuxjournal.com/article/8178

Linux novices often find virtual memory mysterious, but with a grasp of the fundamental concepts, it's easy to understand. 
            With this knowledge,you can monitor your system's 
            memory utilization using vmstat and detect problems that can adversely affect system performance
            
 Q> How Virtual Memory Works
            Physical memory—the actual RAM installed—is a finite resource on any system. 
            The Linux memory handler manages the allocation of that limited resource by freeing portions of physical memory 
            when possible.
            
   All processes use memory, of course, but each process doesn't need all its allocated memory all the time. 
   Taking advantage of this fact, the kernel frees up physical memory by writing some or all of a process' memory to disk until 
   it's needed again.
            
   The kernel uses paging and swapping to perform this memory management. 
   Paging refers to writing portions, termed pages, of a process' memory to disk. 
   Swapping, strictly speaking, refers to writing the entire process, not just part, to disk. 
   In Linux, true swapping is exceedingly rare,but the terms paging and swapping often are used interchangeably.
            
      
            Page-out: When pages are written to disk, the event is called a page-out, and 
            when pages are returned to physical memory, the event is called a page-in. 
            A page fault occurs when the kernel needs a page, finds it doesn't exist in physical memory because 
            it has been paged-out, and re-reads it in from disk

------------------------------------------------------------------Process manager--------------------------------------------
Q> how priority inversion occure
Q> what is priority inheritance
