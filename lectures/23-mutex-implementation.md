Mutex Implementation
====================

Exceptional Circumstances
-------------------------

- Unlocking an already unlocked mutex
- Unlocking a mutex locked by a different thread
- Locking  a mutex that we already hold

Mutex Types
-----------

- PTHREAD_MUTEX_DEFAULT - Produces undefined behavior in exceptional cases
- PTHREAD_MUTEX_ERROR_CHECK - Error codes returned for exceptional cases

Mutex Types
-----------

- PTHREAD_MUTEX_NORMAL - Self-deadlocks are possible. Produces undefined behavior in other cases
- PTHREAD_MUTEX_RECURSIVE - A counter is used for lock state. A mutex can be locked multiple times and must be unlocked the same number of times before truly being unlocked

Monitors
--------

- OOP approach to thread safety
- Provide more structured mutexes

Monitor Objects
---------------

- All state is private
- Objects include a mutex in addition to their state
- Every public method begins by locking the mutex and ends by unlocking it

Races
-----

- A race on object state will be impossible if the object is a monitor

Language support
----------------

- Can be automatic (e.g. `class monitor`)
- [`syncronized`](https://en.cppreference.com/w/cpp/language/transactional_memory#Synchronized_blocks) keyword provides object locking at the method level
- Can be [implemented manually](https://stackoverflow.com/a/48408987)

Mutex Implementation
--------------------

- Atomic instruction is needed that can modify memory and report its previous value
- [`swap`](https://en.wikibooks.org/wiki/X86_Assembly/Data_Transfer#Data_swap) to exchange a register value with memory is sufficient 

Spinlock
--------

- Memory value `1` is unlocked, `0` is locked
- Unlock by storing `1`
- Lock by swapping `0` with the mutex value
  - Locking succeeded if we get a `1` back
  - Otherwise, try until we get a `1` back

---

```lua
to lock mutex:
  let temp = 0
  repeat
    atomically exchange temp and mutex
  until temp = 1
```

---

![Spinlock implementation](media/4-8.png)

Cache-conscious spinlocks
------------------------

- Wait for another thread to change the lock state before atomically locking it
- Avoids poor cache performance while waiting

---

```lua
to lock mutex:
  let temp = 0
  repeat
    atomically exchange temp and mutex
    if temp = 0 then
      while mutex = 0
        do nothing
  until temp = 1
```

Spinlocks
---------

- Explicitly waste CPU time
- Can be appropriate in the case where very little waiting is typically needed due to fast operations
- Does not require a system call

Queuing Mutex
------------

- Avoids spinning
- Components
  - Mutex state
  - Wait queue for waiting threads
  - Cache-conscious spinlock to protect own state

---

![Queuing mutex locking](media/4-12.png)

---

![Queuing mutex unlocking](media/4-13.png)
