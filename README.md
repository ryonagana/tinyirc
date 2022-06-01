# Tinyirc
Experimental Irc Client in C

Only Dependency of pthread (not used yet)
you can safely remove it from CMakelist.txt

## Build
```bash
foo@bar: mkdir my-build
foo@bar: cd my-build
foo@bar: cmake ..
foo@bar: make -j6
```

## Run
```bash
foo@bar: ./cbtinyirc
```

### TODO:
- [x] Create a Socket Wrapper
- [x] Send Message
- [x] Receive Message
- [x] Close Socket
- [x] Auth IRC Using RFC   
- [ ] PING PONG detect
- [ ] Add Simple Bots Commands
- [ ] Loops Running using threads
- [ ] Port for Other OS'es
