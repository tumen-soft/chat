    #include<iostream>

class null_typelist {};

template <class H, class T>
struct typelist
{
    typedef H head;
    typedef T tail;
};

template<class T1, class T2=null_typelist, class T3=null_typelist, class T4=null_typelist> struct cons;

template <class T1>
struct cons<T1, null_typelist, null_typelist,null_typelist>
{
    typedef typelist<T1, null_typelist> type;
};

template <class T1, class T2>
struct cons<T1, T2, null_typelist, null_typelist>
{
    typedef typelist<T1, typelist<T2,null_typelist> > type;
};

template <class T1, class T2, class T3>
struct cons<T1, T2, T3, null_typelist>
{
    typedef typelist<T1, typelist<T2, typelist<T3,null_typelist> > > type;
};

template <class T1, class T2, class T3, class T4>
struct cons
{
    typedef typelist<T1, typelist<T2, typelist<T3,typelist<T4, null_typelist> > > > type;
};


template <class tlist> class AdHocVisitor;

template <class H, class T>
class AdHocVisitor< typelist<H, T> > : public AdHocVisitor<T>
{
public:
    virtual void Visit(H*) = 0;

    template <class SomeClass>
    void StartVisit(SomeClass* p)
    {
        if (H* pFound = dynamic_cast<H*>(p))
        {
            Visit(pFound);
        }
        else
        {
            AdHocVisitor<T>::StartVisit(p);
        }
    }
};

template <class H>
class AdHocVisitor< typelist<H, null_typelist> > 
{
public:
    virtual void Visit(H*) = 0;

    template <class SomeClass>
    void StartVisit(SomeClass* p)
    {
        if (H* pFound = dynamic_cast<H*>(p))
        {
            Visit(pFound);
        }
        else
        {
            throw "Unknown type passed";
        }
    }
};

struct DocElement{virtual ~DocElement(){};};
struct TextArea: DocElement{};
struct Bitmap: DocElement{};
struct VectorGraphics: DocElement{};

int main()
{
    typedef cons<TextArea,Bitmap,VectorGraphics>::type MyHierarchy;

    DocElement *p = new TextArea();

    struct ConcreteVisitor : AdHocVisitor<MyHierarchy>
    {
        void Visit(TextArea* p){std::cout << "I'm a textarea" << "\n";}
        void Visit(VectorGraphics* p){std::cout << "I'm a VectorGraphics" << "\n";}
        void Visit(Bitmap* p){std::cout << "I'm a Bitmap" << "\n";}
    };

    ConcreteVisitor visitor;
    visitor.StartVisit(p);
    delete p;

    std::cin.get();
}
