def hi(cities, cache_size):
    cache =[] 
    time=0
    for city in cities:
        if city.lower() in cache : 
            cache += [city.lower()]
            time += 1
            cache.pop(cache.index(city.lower()))
        elif city.lower() not in cache :
            cache += [city.lower()]
            time += 5
            if len(cache)>cache_size : cache.pop(0)
    return(time)
    #print(hi)