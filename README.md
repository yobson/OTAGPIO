# OTAGPIO

This is a server app written in c (using kore) that will allow remote control (over the air (OTA)) of the GPIO (and some user defined functionality). It will soon be acompnaied by a .net plugin that can use it so you can use it!

##Installation
1. Install [kore](https://kore.io)
2. Clone this repo with the command `git clone https://github.com/yobson/OTAGPIO OTAGPIO`
3. Head into your new OTAGPIO directory.
4. Build the server with `kore build`. Hopefully no errors!
5. In order to contact our server, we need to set up our SSL certificates Head to [This site](http://www.selfsignedcertificate.com/) and type in the IP or hostname that you plan to have the server running on.
6. Download the generated certificates, rename both the .key and .crt file to server.key/.crt and place them in a new folder called cert.
7. We are not done yet. Go into the `/conf` directory and open `OTAGPIO.conf`. Change the IP to whatever your Pi's local IP is. You can also change the port number but 443 is the default for ssl so I wouldn't bother :)
8. We can now start the server by heading back into the root of the project directory and typing `sudo kore run`
9. Type the IP address or Hostname you are using into your browser, there will be a certificate error (becuase we just made a self signed one) but don't worry. Proceed to the site and you should be greeted with a page that says hello world. That means it is working!


##Using
I do plan on building a .net plugin so that you can build UWP apps that can connect to the Pi, but I havent got that far yet! You can still use it, but you will need to write a small library yourself. Luckily, all that invloves are some simple get requests. Here is a little table that will describe the different requests supported at the moment:


|URI|Description|Argument 1|Argument 2|Argument 3|
|---|---|---|---|---|
|/setpinmode|Sets the a pin (use wiringPi numbering) to read or write|num - this is the pin number| state - either READ or WRITE. Must be capitals |*none*|
|/pinwrite|Use to turn a pin on or off if in write mode|num - ditto|state - either 0 or 1 for off or on respectivly|*none*|
|/pinread|Reads boolean value of pin|num - ditto|*none*|*none*|
|/udaction|User Defined Action|action - the numerical id of a user defined action (starts at 0)|data - block of data for action to use| length - size in bytes of data|

Thats it so far :)

##Adding functionality

Adding functionality is done by creating user defined actions (UDActions). These are added in the `UserDefined.h` and `UserDefined.c` files. To add an action, you should create a new function that has a return type of `Data` and an argument of `Data`. `Data` is a typedef struct with this definiation:
```c
typedef struct {
    int dataSize;
    void *data;
} Data;
```
Next, find the `void initUD()` function in the `UserDefined.c` file. Change it so that `numberOfUDActions` is equal to the number of UDActions you have written, add to the actions array the address of each function. The element of the array will be the ID of your function. For example, if I wanted to have three UDActions name one, two and three, after writing the functions, I would change the `void initUD()` function so that it looked like this:
```c
void initUD() {
    atexit(&shutdownUD);
    numberOfUDActions = 3; //Change this to the number of UDActions you have
    actions = malloc(sizeof(UDAction) * numberOfUDActions);
    //Add them to the array here;
    actions[0] = &one;
    actions[1] = &two;
    actions[2] = &three;
}
```
**Don't forget to add your functions to the header file**

- [x] Get it going
- [x] Write Documentation
- [ ] Test it
- [ ] Build .net library for UWP 
