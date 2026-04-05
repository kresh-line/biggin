
voted = {}
def check_voter(name):
  if name in voted:
    print("You have already voted!")
  else:
    voted[name] = True
    print("You can vote!")

while True:
    name = input("Shkruaj emrin (ose 'exit' për të dalë): ")
    if name == "exit":
        break
    check_voter(name)