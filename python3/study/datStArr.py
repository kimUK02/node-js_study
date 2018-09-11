import calendar

a = 16,32,23,61,75,57,83,38,97,79,47,41
print("max",max(a),"[",a.index(max(a)),"]")
print("min",min(a),"[",a.index(min(a)),"]")
print("sum",sum(a))
print("aver",sum(a)/len(a))
cal = calendar.calendar(2018)
print(type(cal))
print(cal)