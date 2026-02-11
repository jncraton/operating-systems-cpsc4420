# 1.7 Supporting Interactions Across Time

## Storage

- OS provides long-term storage for computation results
- Results can be retrieved for future computations

## File system

- Named persistent storage
- Typically organized in a hierarchy

## File access

- Accessed via OS APIs (`read`, `write`)
- May be mapped to memory space and accessed directly with `load` and `store`

## Databases

- Provide persistent storage
- Allows related data to be access easily

---

What if the system goes down during a write?

## Crashes

- Any operation should be immediately interruptable without leaving persistent storage in a degraded state
- Atomic transactions and journaling may be a solution to this
