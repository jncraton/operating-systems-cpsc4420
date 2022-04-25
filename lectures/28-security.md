11 Security
===========

Security
--------

- Pervasive within all parts of the OS
- Similar to performance, every layer of the OS must consider security

Risk Management
---------------

- Security involves balancing risk
- Cost of security enhancement
- Likelihood of failure
- Cost of failure

---

> A system is secure if it is designed, implemented, and operated so as to reduce to an appropriate level the risk that it will fail to meet the objectives of its owner, even in the face of adversaries.

Non-technical risk management
-----------------------------

- Re-entering valuable data (e.g. CC numbers)
- Employee training
- Morale

Objectives
----------

- Confidentiality
- Integrity
- Availability
- Accountability

Authentication
--------------

- Required to meet all for objectives
- Users must be correctly identified on a system

Principles
----------

- Economy of mechanism
- Fail-safe defaults
- Complete mediation
- Open Design
- Separation of privilege
- Least privilege

Principles
----------

- Psychological acceptability
- Work factor
- Compromise recording
- Defense in depth
- Alignment of authority and control
- Physical security

Economy of Mechanism
--------------------

- Simple designs consistently using a small number of mechanisms should be more secure
- A single, general purpose transaction mechanism is easier to audit than different approaches to concurrency used throughout a system

Fail safe defaults
------------------

- Access is withheld by default
- Errors always result in too little authority
- Users will report errors

Complete mediation
------------------

- Every access is checked by another authority
- Authorization in the past does not equate to authorization in the present

Open Design
-----------

- The only secret parts of a secure system should be keys and passwords
- The design should be openly inspected by as many parties as will look at it
- Examples include cryptographic algorithms (TLS, SHA, etc) along with their implementations (OpenSSL, OpenSSH, etc)

Separation of Privilege
-----------------------

- No single user should be able to perform certain highly privileged operations
- This prevents corruption of key users

---

![Two-person concept](https://upload.wikimedia.org/wikipedia/commons/7/78/SAS_Container.png)

[USAF Documentation](https://irp.fas.org/doddir/usaf/afi91-104.pdf)

Least Privilege
---------------

- Each process should operate using only the privileges required and no more
- Bugs in processes thus allow the smallest number of inappropriate operations

Psychological Acceptability
---------------------------

- Security mechanisms must have well-designed interfaces
- Complexity should be hidden
- Measures in place should be effective and needed

Work Factor
-----------

- The cost of breaking into a system should cost more than the value of the system
- Cryptographic key length should be appropriate
- Work functions for hashing should be appropriate

Compromise Recording
--------------------

- System logging should be tamper-proof
- Breaches should be recorded in a reliable manner
- Technical and/or legal responses can be mounted

Defense in Depth
----------------

- Attackers should need to breach multiple independent security boundaries to break a system
- Password, second factor, IP allow list, firewall, etc

Alignment of Authority and Control
----------------------------------

- The same user who supplies credentials for an action should perform the action
- Trojan horse programs perform different actions than a user expects
- setuid programs operate with their authors authority rather than their users

Physical security
-----------------

- Owners should control physical access to systems
- Encrypted drives must be protected from theft

Adversaries
-----------

- Can be internal
- Can be users falling victim to [social engineering](https://www.youtube.com/watch?v=lc7scxvKQOo)
- Can be an external attacker using technical means

