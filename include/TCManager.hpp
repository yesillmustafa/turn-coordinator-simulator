#ifndef TCManager_hpp
#define TCManager_hpp


class TurnCordinator;

class TCManager
{
    public:
    
    static TCManager* getInstance();
    TurnCordinator* createCircle();
    TurnCordinator* createNeedle();
    TurnCordinator* createBall();
    
    private:
    static TCManager* m_Instance;
    TCManager();
};

#endif