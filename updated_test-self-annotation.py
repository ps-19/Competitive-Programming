import torch


@torch.jit.script
class MyClass(object):
   def __init__(self , x: int):
      self.x = x

   def inc(self, val: int):
      self.x += val

def fn(a: MyClass, b: int):
    a.inc(b)
    return a.x

x = MyClass(1)
print("Eager: ", fn(x, 100))

x = MyClass(1)
scripted_fn = torch.jit.script(fn)
print("Scripted: ", scripted_fn(x, 100))