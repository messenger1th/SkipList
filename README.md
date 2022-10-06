# Skip List



## Interface

* `insert(K, V)`
* `erase(K)`
* `erase_all(K)`
* erase_range(Lower, Upper)

**Display**

* `print_list()`
* `print_list_level()`

**Other**: Some Getter





## Development Log

### Version 1.0: Template & Single Thread

**Feature**

1. Template for any type of Key & Value
2. support same value insertion
3. support single key erase and erase_all key
4. support range erase



### Version 2.0: Support Multi-Task

**Feature**

1. use `shared_mutex` (Since C++17) support for multi thread read & write.



## Performance



## Updating

1. Use Thread Pool (Based On C++14) for Unit Test, which is more practicable.
2. Use More Modern Feature of C++, such as `package_task`, 
3. Use more small granularity lock for better Read & Write performance.
4. Use makefile for better extension & compile performance.
5. Use More systematic test frame for Unit Test: Like Docker ?  
