4.4 Other Synchronization Patterns
=================================

Naive Bounded Buffer
------------------------

```python
producer:
    while True:
        while (queue.isFull()) # Wait for space
        queue.append(task)

consumer:
    while True:
        while (queue.isEmpty()) # Wait for work
        doStuff(queue.pop())
```

Spin-waiting Producer
------------

```python
producer:
    while True:
        queue.lock()
        while (queue.isFull()):
            queue.unlock()
            queue.lock()

        queue.append(task)
        queue.unlock()
```

Spin-waiting Consumer
------------

```python
consumer:
    while True:
        queue.lock()
        while (queue.isEmpty()):
            queue.unlock()
            queue.lock()

        task = queue.pop()
        doStuff(task)
        queue.unlock()
```

Pipes
-----

- Provide OS-level support for bounded buffers between processes
- `du | sort -n`

Readers/Writers Locks
---------------------

- Alternative to mutex
- Allows lock to specify whether thread is reading or writing
- Only one writer may access the mutex at a time, but multiple readers are allowed

---

![Readers/Writers Lock](media/4-15.png)

Barriers
--------

- Requires multiple concurrent threads to finish a task before moving on
- Similar to our use `pthread_join`, but does not require threads to terminate

Condition Variables
------------------

- Provide a way to bundle multiple threads waiting on the same condition
- A signaling mechanism is used to wake threads when the condition is met

Condition Variable Producer
---------------------------

```python
producer:
    while True:
        queue.lock()
        while (queue.isFull()):
            queue.unlock()
            wait(fullCV) # Sleep
            queue.lock()

        queue.append(task)
        signal(emptyCV)
        queue.unlock()

```

Condition Variable Consumer
---------------------------

```python
consumer:
    while True:
        queue.lock()
        while (queue.isEmpty()):
            queue.unlock()
            wait(emptyCV) # Sleep
            queue.lock()

        task = queue.pop()
        signal(fullCV)
        doStuff(task)
        queue.unlock()
```

Semaphores
----------

- Somewhat similar to a mutex, but can take on values other than 0 and 1
- A semaphore that uses only 0 and 1 is a mutex
- Larger counter values can be useful when implementing bounded buffers or other concurrency mechanisms
