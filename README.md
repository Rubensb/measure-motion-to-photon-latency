# Motion and Click to Photon Latency Measurements Project TU Berlin

## How to connect to ardunio serial monitor (linux/mac)

1. Find usb device

```sh
ls /dev | grep usb
```

2. Copy name

```txt
cu.usbmodem1101 <---- looks like this
tty.usbmodem1101
```

3. Run `screen` command (600 is the baud rate)

```sh
screen /dev/cu.usbmodem1101 600
```

4. Done
5. To exit press `ctrl+a+k` and confirm with `y`
