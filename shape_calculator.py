class Rectangle:

    def __str__(self):
        return "Rectangle(width="+str(self.width)+", height="+str(self.height)+")"

    def __init__(self,x,y):
        self.width = x
        self.height = y


    def set_width(self, width):
        self.width = width


    def set_height(self, height):
        self.height = height


    def get_area(self):
        return self.width*self.height

    def get_perimeter(self):
        return (2 * self.width + 2 * self.height)


    def get_diagonal(self):
        return ((self.width ** 2 + self.height ** 2) ** .5)

    def get_picture(self):
        if self.height>50 or self.width>50:
            return "Too big for picture."
        else:
            string = ""
            for x in range(self.height):
                string = string+"*"*self.width+"\n"
            return string

    def get_amount_inside(self,shape):
        return int((self.width*self.height)/(shape.width*shape.height))





class Square(Rectangle):
    def __init__(self,side):
        self.width = side
        self.height = side

    def set_side(self,length):
        self.height = length
        self.width = length

    def set_width(self, width):
        self.width = width
        self.height = width

    def set_height(self, height):
        self.height = height
        self.width = height

    def __str__(self):
        return "Square(side="+str(self.width)+")"


