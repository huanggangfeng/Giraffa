# The class is made up of attributes (data) and methods (functions).
# Attributes and methods are simply defined as normal variables and functions.
# As noted in the corresponding docstring, the __init__() method is called the initializer. It's equivalent to the constructor in other object oriented languages, and is the method that is first run when you create a new object, or new instance of the class.
# Attributes that apply to the whole class are defined first, and are called class attributes.
# Attributes that apply to a specific instance of a class (an object) are called instance attributes. They are generally defined inside __init__(); this is not necessary, but it is recommended (since attributes defined outside of __init__() run the risk of being accessed before they are defined).
# Every method, included in the class definition passes the object in question as its first parameter. The word self is used for this parameter (usage of self is actually by convention, as the word self has no inherent meaning in Python, but this is one of Python's most respected conventions, and you should always follow it).
# Those used to object-oriented programming in other languages may be surprised by a few things. One is that Python has no real concept of private elements, so everything, by default, imitates the behavior of the C++/Java public keyword. For more information, see the "Private Class Members" example on this page.
# Some of the class's methods have the following form: __functionname__(self, other_stuff). All such methods are called "magic methods" and are an important part of classes in Python. For instance, operator overloading in Python is implemented with magic methods.


class Person(object):
    """A simple class"""
    species = "tteehakh"

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name

    def rename(self, renamed):
        self.name = renamed;

kelly = Person('kelly')

print (kelly.name)
kelly.rename('hg')
print (kelly.name)

print (kelly.__str__())
