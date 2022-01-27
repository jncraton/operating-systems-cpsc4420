from manim import *

class OpeningManim(Scene):
    def construct(self):
        self.camera.background_color = WHITE
    
        rq_label = Text("Run Queue", color=BLACK)
        rq_label.shift(LEFT*4)
        rq_label.shift(UP*3)
        wq_label = Text("Disk Wait Queue", color=BLACK)
        wq_label.shift(RIGHT*4)
        wq_label.shift(UP*3)
        self.add(rq_label)
        self.add(wq_label)

        rq = Square(4,color=BLACK)
        rq.shift(RIGHT*4)
        wq = Square(4,color=BLACK)
        wq.shift(LEFT*4)
        self.add(rq)
        self.add(wq)

        a = Text("Thread A", color=BLACK)
        a.shift(UP*1)
        a.shift(LEFT*4)
        self.add(a)

        b = Text("Thread B", color=BLACK)
        b.shift(LEFT*4)
        self.add(b)

        c = Text("Thread C", color=BLACK)
        c.shift(UP*1)
        c.shift(RIGHT*4)
        self.add(c)

        d = Text("Thread D", color=BLACK)
        d.shift(RIGHT*4)
        self.add(d)

        text = Text("Thread A reads from file", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            a.animate.shift(RIGHT*8, DOWN*2),
            b.animate.shift(UP*1),
        )
        self.remove(text)

        text = Text("Read completes for thread C", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            c.animate.shift(LEFT*8, DOWN*1),
            d.animate.shift(UP*1),
            a.animate.shift(UP*1),
        )
        self.remove(text)

        text = Text("Read completes for thread D", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            d.animate.shift(LEFT*8, DOWN*2),
            a.animate.shift(UP*1),
        )
        self.remove(text)

        text = Text("Thread B reads from file", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            b.animate.shift(RIGHT*8, DOWN*1),
            c.animate.shift(UP*1),
            d.animate.shift(UP*1),
        )
        self.remove(text)

        text = Text("Thread C reads from file", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            c.animate.shift(RIGHT*8, DOWN*2),
            d.animate.shift(UP*1),
        )
        self.remove(text)

        text = Text("Read completes for thread A", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            a.animate.shift(LEFT*8, DOWN*1),
            b.animate.shift(UP*1),
            c.animate.shift(UP*1),
        )
        self.remove(text)

        text = Text("Read completes for thread B", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            b.animate.shift(LEFT*8, DOWN*2),
            c.animate.shift(UP*1),
        )
        self.remove(text)

        text = Text("Thread D reads from file", color=BLACK)
        text.shift(DOWN*3)
        self.add(text)
        self.play(
            d.animate.shift(RIGHT*8, DOWN*1),
            a.animate.shift(UP*1),
            b.animate.shift(UP*1),
        )
        self.remove(text)
