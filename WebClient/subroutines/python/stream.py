import subprocess, sys

def kill_stream():
        subprocess.call(["killall","ffmpeg","&&","killall","raspivid"])

def start_stream(dir): # dir allows stream to be started from parent or current directory
        subprocess.call(["sh",dir+"/bash/stream.sh"])

if __name__ == "__main__":
        start_stream("..")
        while True:
                try:
                        pass
                except KeyboardInterrupt:
                        kill_stream()
                        sys.exit()
