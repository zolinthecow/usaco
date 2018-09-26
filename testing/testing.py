cowCount = input() 
initialGallons = input()
cowProduction = []
for i in range(0,1000000):
    cowProduction.append( initialGallons )
productionChanges = {}
for i in range(0,cowCount):
    day = input()
    a = input(), b = input()
    productionChanges[day] = (a, b)
sorted(productionChanges)

    


