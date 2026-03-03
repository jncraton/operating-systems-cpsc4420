all: run-queue.gif priority.gif

%.gif: %.py
	uvx manim -ql --format=png $<
	mkdir -p frames_$*
	mv media/images/$*/*.png frames_$*/
	gifski -o $@ frames_$*/*.png
	rm -rf frames_$*

clean:
	rm -rf __pycache__ media *.gif frames_*
