import subprocess, time

def kill_stream():
        subprocess.call(["killall","ffmpeg","&&","killall","raspivid"])

def start_stream(dir): # dir allows stream to be started from parent or current directory
        subprocess.call(["sh",dir+"/bash/stream.sh"])

if __name__ == "__main__":
        start_stream("..")
        time.sleep(30)
        kill_stream()
