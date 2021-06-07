# Alpha-Hash

&nbsp;
![](resources/image.jpg)

&nbsp;
a 256-Bit hashing function coded in C++

&nbsp;
### Hash Info
- Hash speed is around 1e7/s
- Hash digits are [a-fA-F0-9]
- Collision tested ( no collision in 11 april 2021)

&nbsp;
### Hashing in windows
hash text string ( salt can be null )
```
Alpha [STRING-DATA] [SALT]
```
hash any file ( salt can be null )
```
Alphaf [PATH-OF-DATA] [SALT]
```

&nbsp;
### Hashing in linux/mac
hash text string ( salt can be null )
```
./Alpha [STRING-DATA] [SALT]
```
hash any file ( salt can be null )
```
./Alphaf [PATH-OF-DATA] [SALT]
```

&nbsp;
### Example
```
< Alpha test
> Alpha( e6c6D8C7E6C5e7d6E8E8a7f7d70D8aD63A7a3e5a5b9a7b7a8E8A5B6A81A9f8b6 )
< Alpha test aSalt452
> Alpha( 5a1b6a6a2B5a7E9a9f5a9c6A80b54b64b7a3B5d5B7b9a6c8B7d8C5a8c6D7C7A7 )
```
