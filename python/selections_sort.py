# Gjen elementin me te vogel ne nje liste
def findSmallest(arr):
    smallest = arr[0]          # Supozojme qe elementi i pare eshte me i vogli
    smallest_index = 0         # Ruajme poziten e tij
    for i in range(1, len(arr)):       # Kalojme neper cdo element tjeter
        if arr[i] < smallest:          # Nese gjejme nje me te vogel
            smallest = arr[i]          # Perditesojme vleren me te vogel
            smallest_index = i         # Perditesojme poziten
    return smallest_index      # Kthejme poziten e elementit me te vogel


# Rendit listen duke gjetur here pas here elementin me te vogel
def selectionSort(arr):
    newArr = []                # Lista e re ku do te vendosen elementet e renditur
    copiedArr = list(arr)      # Kopjojme listen origjinale qe te mos e ndryshojme
    for i in range(len(copiedArr)):            # Perserisim per cdo element
        smallest = findSmallest(copiedArr)     # Gjejme poziten e me te voglit
        newArr.append(copiedArr.pop(smallest)) # E heqim nga kopja dhe e shtojme ne listen e re
    return newArr              # Kthejme listen e renditur

print(selectionSort([5, 3, 6, 2, 10]))
