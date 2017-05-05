#simple hello world exploring some functionality of julia


#strings
s1 = "hello"	#strings use double quotes
c1 = 'w'	#chars use single quotes

print(s1, " ", c1, "orld", "\n")

#use of array and loop
a1 = collect(1:10)
for i in a1
	print(i, " ")
end


#use of types
type animal
	name::AbstractString
	pet::Bool
end

g = animal("giraffe", false)



print("\ng is a ",  g.name, "\n")