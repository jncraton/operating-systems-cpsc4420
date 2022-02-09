all: run-queue.gif priority.gif

%.gif: %.py
	manim -ql --format=gif $< -o $@
	mv media/videos/*/*/*.gif .
	gifsicle --optimize=3 --lossy=200 $@ -o $@

clean:
	rm -rf __pycache__ media *.gif