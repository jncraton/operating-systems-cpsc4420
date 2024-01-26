Booting
=======

Execution
---------

- A CPU loads the next instruction from memory
- This instruction is executed
- This process repeats

---

Where does the first in struction come from?

Volatility
----------

- Most operating systems are stored in non-volatile memory
- CPUs in most computers execute instructions from volatile memory
- A set of operations is needed to move the operating system to a location that is executable

First-stage boot loader
-----------------------

- Most modern systems include multiple stages of booting
- The first step typically involves loading and executing firmware from a dedicated storage device
- Examples include BIOS and UEFI

Second-stage boot loader
------------------------

- The initial boot loader is usually tightly coupled to the device
- It is basic and has limited size
- It is used to load a more complete bootloader that loads the full OS
- Examples include GRUB, Syslinux, NTLDR, and BOOTMGR

GRUB
----

- Popular boot loader used with Linux systems
- Supports multiple operating systems

---

![GRUB OS Selection](https://upload.wikimedia.org/wikipedia/commons/4/48/Debian_Unstable_GRUB2_%282015%29.png)
