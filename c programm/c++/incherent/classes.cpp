class Base
{
public:
    int x;
protected:
    int y;
private:
    int z;
};
class PublicDerived : public Base
{
    void changeX(int x1) {
        x = x1; // OK: x is public in Base
    }
    void changeY(int y1) {
        y = y1; // OK: y is protected in Base
    }
    void changeZ(int z1) {
        //z = z1; // Error: z is private in Base
    }
};
class ProtectedDerived : protected Base
{
     void changeX(int x1) {
        x = x1; // OK: x is public in Base
    }
    void changeY(int y1) {
        y = y1; // OK: y is protected in Base
    }
    void changeZ(int z1) {
        //z = z1; // Error: z is private in Base
    }

    };
class PrivateDerived : private Base
{
     void changeX(int x1) {
        x = x1; // OK: x is public in Base
    }
    void changeY(int y1) {
        y = y1; // OK: y is protected in Base
    }
    void changeZ(int z1) {
        z = z1; // Error: z is private in Base
    }

};
 int main()
 {
        PublicDerived publ1;
        publ1.x = 1;
        cout << publ1.x << endl;     // OK: x is public in PublicDerived
        //publ1.y = 20; // Error: y is protected in PublicDerived
        //publ1.z = 30; // Error: z is private in PublicDerived
    
        ProtectedDerived prot1;
        //prot1.x = 10; // Error: x is protected in ProtectedDerived
       // prot1.y = 20; 
        //cout << prot1.y << endl;     // Error: y is protected in ProtectedDerived
        //prot1.z = 30; // Error: z is private in ProtectedDerived
    
        PrivateDerived priv1;
        //priv1.x = 10; // Error: x is private in PrivateDerived
        //priv1.y = 20; // Error: y is private in PrivateDerived
        //priv1.z = 30;
        cout << priv1.z << endl;     // Error: z is private in PrivateDerived
    
        return 0;
 }