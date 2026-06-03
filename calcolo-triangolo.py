import math
def control(L):
    if (L[0] + L[1] > L[2]) and (L[0] + L[2] > L[1]) and (L[1] + L[2] > L[0]) and (L[0] != 0) and (L[1] != 0) and (L[2] != 0):
        return 1
    else:
        return 0
def main():
    L = [0.0, 0.0, 0.0]
    A = [0.0, 0.0, 0.0]
    tentativi = 3
    i = 1
    valido = False
    while i <= tentativi:
        print("inserisci i dati del triangolo")
        try:
            L[0] = float(input("segmento AB\n"))
            L[1] = float(input("segmento BC\n"))
            L[2] = float(input("segmento CA\n"))
        except ValueError:
            print("Per favore, inserisci un numero valido.")
            continue
        if not control(L):
            print("i dati inseriti non possono formare un triangolo, riprova. hai ancora {tentativi - i}° tentativi")
            if i >= tentativi:
                print("non sai la regola di un triangolo sei una capra")
                return
            i += 1
        else:
            valido = True
            break      
    if not valido:
        return
    A[0] = math.degrees(math.acos((L[1]**2 + L[2]**2 - L[0]**2) / (2 * L[1] * L[2])))
    A[1] = math.degrees(math.acos((L[0]**2 + L[2]**2 - L[1]**2) / (2 * L[0] * L[2])))
    A[2] = math.degrees(math.acos((L[0]**2 + L[1]**2 - L[2]**2) / (2 * L[0] * L[1])))
    perimetro = L[0] + L[1] + L[2]
    semiperimetro = perimetro / 2
    area = math.sqrt(semiperimetro * (semiperimetro - L[0]) * (semiperimetro - L[1]) * (semiperimetro - L[2]))
    if L[0] == L[1] == L[2]:
        print("è un triangolo equilatero")
    elif L[0] == L[1] or L[0] == L[2] or L[1] == L[2]:
        print("è un triangolo isoscele")
        if 90.0 in L:
            print("è anche un triangolo rettangolo")
    else:
        print("è un triangolo scaleno")
        if 90.0 in L:
            print("è anche un triangolo rettangolo")
    print(f"angolo alfa è: {A[0]:.3f}")
    print(f"angolo beta è: {A[1]:.3f}")
    print(f"angolo gamma è: {A[2]:.3f}")
    print(f"il perimetro del triangolo è: {perimetro:.3f}")
    print(f"l'area del triangolo è: {area:.3f}")
    with open("dati-python.txt", "w") as file:
        file.write(f"segmento AB: {L[0]:.3f}\n")
        file.write(f"segmento BC : {L[1]:.3f}\n")
        file.write(f"segmento CA : {L[2]:.3f}\n")
        file.write(f"angolo alfa : {A[0]:.3f}\n")
        file.write(f"angolo beta : {A[1]:.3f}\n")
        file.write(f"angolo gamma: {A[2]:.3f}\n")
        file.write(f"perimetro : {perimetro:.3f}\n")
        file.write(f"area : {area:.3f}\n")  
    print("dati salvati su file")
if __name__ == "__main__":
    main()