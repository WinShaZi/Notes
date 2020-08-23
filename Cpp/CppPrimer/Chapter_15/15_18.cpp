/*

Base *p = &d1;          // d1的类型是Pub_Derv，合法
                        // 如果是保护或私有继承，则派生类不能向基类转换
p = &d2;                // d2的类型是Priv_Derv,非法
p = &d3;                // d3的类型是Prot_Derv，非法
p = &dd1;               // dd1的类型是Derived_from_Public，合法
p = &dd2;               // dd2的类型是Derived_from_Private，非法
p = &dd3;               // dd3的类型是Derived_from_Protected，非法

*/