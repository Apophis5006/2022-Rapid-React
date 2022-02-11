
class AutoStateMachine{

    enum class Command {START,STOP,funct};

//    tuple<Commands> Commands; //add once problem fixed with tuple



    AutoStateMachine(Command code[]){ //takes in an array of the code

    }
    void Run(Command code[]){   //runs stored code in object
        for(int i=0;i<sizeof(code);i++){
           if(RunLine(code[i]))break; 
        }
    }

    bool RunLine(Command line){ //runs individual line of auto code
        switch(/*get<0>(*/line){
               case Command::START: break;
               case Command::STOP: return false; //used for stoping mid code
            }
        return true;
    }

};