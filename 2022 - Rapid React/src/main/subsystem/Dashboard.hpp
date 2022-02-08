template <class fieldDataType> //the data type of the fields

/*
An abstract class for interfacing with the SmartDashboard UI
*/
class Dashboard {
protected:
    //Variables
    const string BASE_KEY; //the base access key

    const string FIELD_NAME; //the name of the field scope for accessing the SmartDashboard UI 
    const int MAX_SCOPE; //the max scope of the field in the SmartDashboard UI

    //Methods
    /*
    Formats the base key formated to the provided scope

    @param fieldScope the scope of the field being accessed
    @returns the access key for the specified scope
    */
    string GetKey(int scope) {
        return fmt::format(this->BASE_KEY, fmt::arg("field", this->FIELD_NAME), fmt::arg("scope", scope)));
    }

public:
    //Constructors
    /*
    Creates a dashboard object
    */
    Dashboard(string fieldName, int maxScope = 6, string baseKey = "DB/{field} {scope}") : FIELD_NAME(fieldName),MAX_SCOPE(maxScope),BASE_KEY(baseKey) {}

    /*
    Retrieves the input of a scope

    @param scope the scope being accessed
    @returns data in field
    */
    fieldDataType GetData(int scope) {
        return frc::SmartDashboard::GetRaw(this->GetKey(scope),"");
    }
    /*
    Retrieves the input states

    @returns an array containing the value of each field division
    */
    fieldDataType* GetData() {
        fieldDataType fieldData[this->MAX_FIELDS];

        for (int scope = 0; scope < this->MAX_FIELDs; scope++) {
            fieldData[scope] = this->GetData(scope);
        }
        return fieldData;
    }

    /*
    Sets the state of a field scope

    @param scope the scope of the field being set
    @param value the value being set
    */
    void SetState(int scope, fieldDataType value) {
        frc::SmartDashboard::PutRaw(this->GetKey(scope), value);
    }
    /*
    Sets the state of a field scope
    */
    void SetState(fieldDataType values[]) {
        for (int scope = 0; scope < this->MAX_FIELDs; scope++) {
            this->SetState(scope, values[scope]);
        }
    }
};