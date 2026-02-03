*This project has been created as part of the 42 curriculum by elzekaj.*

# Minitalk

## Description

Minitalk is a small data exchange program that uses UNIX signals to communicate between a client and a server. The client sends a string message to the server one bit at a time using only two signals: `SIGUSR1` and `SIGUSR2`.

**How it works:**
- Each character is converted to its binary representation (8 bits)
- `SIGUSR1` represents a bit value of 1
- `SIGUSR2` represents a bit value of 0
- The server reconstructs each character by accumulating 8 bits, then prints it

## Instructions

### Compilation

```bash
make        # Build client and server
make clean  # Remove object files
make fclean # Remove object files and executables
make re     # Rebuild everything
```

### Usage

1. Start the server in one terminal:
```bash
./server
```
The server will display its PID (Process ID).

2. In another terminal, send a message:
```bash
./client <server_pid> "Your message here"
```

### Example

```bash
# Terminal 1
$ ./server
Server PID: 12345

# Terminal 2
$ ./client 12345 "Hello, World!"

# Terminal 1 displays: Hello, World!
```

## Resources

- [GNU C Library - Signal Handling](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html)
- [POSIX Signals](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/signal.h.html)
- `man sigaction`, `man kill`, `man signal`
