
arr = gets.strip
arr = arr.split

arr = arr.each.map(&:to_i)

N, A, B = arr;

R1 = "YES"
R2 = "NO"
arreglo = []
arrRe = []
i =  B
cant = 10**5

if 1 <= N && N <= 10**15
    
    if 1 <= A && A <= B && B <= 10**15
        
        for i in (A..B)
            arrRe.push(i) #agregando primer elemento

            while(arrRe.sum <= N && arrRe.size <= 10**5)
                arrRe.push(A) #agregando demas elementos
                
                for k in (A..B)
                    arrRe[arrRe.size-1] = k
                    
                    if arrRe.sum == N #si es igual agregar 
                        arreglo.push(arrRe.clone)
                    end
                end
                
                arrRe[arrRe.size-1] = A
            end
            
            arrRe.clear
        end
        
        if arreglo.size == 0
            puts R2
        else
            puts R1
        end
        arreglo.each do |e|
            p e
        end
        
    end#valido
end
