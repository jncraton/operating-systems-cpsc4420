5.3 Atomic Transaction Mechanisms
=================================

Guarantees
----------

- Current transactions are isolated from one another
- Failed transactions have no visible effects

Serializability
---------------

- Concurrent transactions may execute simultaneously as long as they do not interfere
- They must execute as if running serially
- Execution that is equivalent to serial executions is called serializable