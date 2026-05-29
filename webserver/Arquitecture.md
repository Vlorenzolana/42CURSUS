## The project file map

Here is every file the project will eventually contain, organised by owner, so you can track progress:

```
webserv/
│
├── Makefile                          ← you write this on day one
│
├── includes/                         ← everything you write before the meeting
│   ├── Shared.hpp                    YOU  (file 1)
│   ├── ServerConfig.hpp              YOU  (file 2)
│   ├── HttpRequest.hpp               YOU  (file 3)
│   ├── HttpResponse.hpp              YOU  (file 4)
│   ├── Client.hpp                    YOU  (file 5)
│   ├── ConfigParser.hpp              YOU  (stub ready at meeting)
│   ├── ServerManager.hpp             Member 1 (stub you hand them)
│   └── RequestHandler.hpp            Member 3 (stub you hand them)
│
├── src/
│   ├── main.cpp                      YOU
│   ├── ConfigParser.cpp              YOU
│   ├── HttpRequestParser.cpp         YOU
│   ├── HttpResponse.cpp              YOU  (serialize() lives here)
│   ├── advanceState.cpp              YOU
│   │
│   ├── ServerManager.cpp             Member 1
│   ├── Socket.cpp                    Member 1
│   │
│   ├── RequestHandler.cpp            Member 3
│   ├── CGIHandler.cpp                Member 3
│   └── ErrorPageBuilder.cpp          Member 3
│
└── config/
    └── default.conf                  YOU (write during CP1, needed for testing)
```

---
