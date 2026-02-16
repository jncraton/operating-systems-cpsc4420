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

# 1.8 Supporting Interactions Across Space

## Networking

- Provides a means for separate systems to interact
- Network stack organized into layers

## Sockets

- Provides a standard and consistent API for applications to use for networking
- Supports streaming and packet-based communication

## Socket types

- Stream - provides a virtual circuit
- Datagram - delivers individual packets

## Socket Implementation

- Independent of network type
- Most typically used with TCP/IP and UDP/IP

---

```c
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
  return 1;
}

if( connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0) {
  return 1;
}

if (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) <= 0) {
  return 1;
}

printf("%s\n", recvBuff);
```

# 1.9 Security

## Threats

- Operating systems need to be able to behave correctly in the face of malicious actors

## Objectives

- Confidentiality
- Integrity
- Availability
- Accountability

---

![CIA Triad](https://www.nist.gov/sites/default/files/images/2022/09/09/cyber-triad-1.png){height=540px}

