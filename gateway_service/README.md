# Gateway Service

## Verification
1)  Build
```
cmake --build build -j 4
```

2) Run
The executable is located in build/bin/.

```
./build/bin/gateway
```

3) Expected Output:
```
Gateway Service running on port 4000...
```

4) Test Endpoint
Verify the service is responding:

```
curl -v http://localhost:4000/help
```
Expected Response:
```
HTTP/1.1 200 OK
Server: oatpp/1.4.0
Content-Length: 83
Gateway Service v0.1.0 
 Available endpoints:
	 GET /gateway/health
	 GET /gateway/
```