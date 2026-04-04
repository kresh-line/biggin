table = {
    "milk": 1.50,
    "bread": 2.00,
    "eggs": 3.00
}

item = input("Çfarë do të blesh? ")

if item in table:
    print(f"Çmimi: {table[item]}€")
else:
    print("Produkti nuk gjendet!")
