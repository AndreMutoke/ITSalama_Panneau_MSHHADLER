
//=============================================================================================================
//==============================NEW_METHOD_BY_GODWIN_AND_ANDRE============================================
//=============================================================================================================

#ifndef MSGHANDLER_HPP
#define MSGHANDLER_HPP

#include <c++/8.4.0/iostream>
#include <c++/8.4.0/string>

#define VERT 63488
#define ROUGE 2016
#define BLANC 65535//BLANC
#define BLEU 31
#define MAGENTA 2047
#define CYAN 63519
#define JAUNE 65504
#define NOIR 0
struct MessageColor
{
   uint16_t txtColor;//Couleur du message
   uint16_t bkgndColor;//Couleur de fond/background(bkgnd) du message
};
typedef struct MessageColor MsgColor;
struct GreenRedBlue
{
   uint8_t g;//Couleur verte
   uint8_t r;//Couleur rouge
   uint8_t b;//Couleur blue
};
typedef struct GreenRedBlue GRB;
struct Coordonnees
{
    int xPos; // coordonnée X
    int yPos; //  coordonnée Y
};
typedef struct Coordonnees Coord;

class MsgPanel{
private:
    MsgColor colorMsg;
    Coord posMsg;
    int sizeMsg;
    bool defilement;
    std::string msg;
public:
    MsgPanel(std::string& txt, 
            MsgColor color = {(uint16_t)BLEU,(uint16_t)NOIR}, 
            Coord position = {0, 0}, 
            int sizeTxt = 1 , bool scroll = false):
                        msg(txt),
                        colorMsg(color),
                        posMsg(position),
                        sizeMsg(sizeTxt),
                        defilement(scroll)
    {
        //constructor
    }
    MsgPanel(const char txt[], 
            MsgColor color = {(uint16_t)BLEU,(uint16_t)NOIR}, 
            Coord position = {0, 0}, 
            int sizeTxt = 1 , bool scroll = false):
                        msg(txt),
                        colorMsg(color),
                        posMsg(position),
                        sizeMsg(sizeTxt),
                        defilement(scroll)
    {
        //constructor
    }

    //========================SET_METHODS============================================
    void setColor(MsgColor color){MsgPanel::colorMsg = color;}
    void setTxtColor(uint16_t txtColor, uint16_t bckgndColor = (uint16_t)0){
        MsgPanel::colorMsg.txtColor = txtColor;
        MsgPanel::colorMsg.bkgndColor = bckgndColor;
        
        }
    void setCoord(Coord position){MsgPanel::posMsg = position;}
    void setSize(int policy){MsgPanel::sizeMsg = policy;}
    void setMsg(std:: string newMsg){MsgPanel::msg = newMsg;}
    void setMsg(const char* newMsg){MsgPanel::msg = (std::string)newMsg;}
    void setCoordX(int x){MsgPanel::posMsg.xPos = x;}
    void setCoordY(int y){MsgPanel::posMsg.yPos = y;}
    void setScroll(bool scroll){MsgPanel::defilement = scroll;}
    //=========================GET_METHODS=================================
    MsgColor getColor(){return MsgPanel::colorMsg;}
    Coord getCoord(){return MsgPanel::posMsg;}
    int getSize(){return MsgPanel::sizeMsg;}
    bool getScrollStatus(){return MsgPanel::defilement;}
    std::string getMsg(){return MsgPanel::msg;}
    const char* getChar(){return msg.c_str();}
    int getNbChar(){return MsgPanel::msg.size();}
    int getWidth(){return (int)((MsgPanel::msg.size() * 6 * MsgPanel::sizeMsg) - MsgPanel::sizeMsg);}
};
#endif // MSGHANDLER_HPP
