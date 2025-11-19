#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
#include <sql.h>
#include <sqlext.h>

int _tmain(int argc, _TCHAR* argv[]) {
    SQLHENV hEnv = NULL;
    SQLHDBC hDbc = NULL;
    SQLHSTMT hStmt = NULL;
    SQLRETURN ret;

    // Define an ODBC connection string
    SQLCHAR* connectionString = (SQLCHAR*)"DRIVER={Devart ODBC Driver for Oracle};Direct=True;Host=localhost;Service Name=xe;User ID=SYSTEM;Password=25092012";

    // Allocate an environment handle
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    if (ret == SQL_ERROR) {
        wprintf(L"Unable to allocate an environment handle\n");
        exit(-1);
    }

    // Set the ODBC version environment attribute
    SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);

    // Allocate a connection handle
    ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
    if (ret == SQL_ERROR) {
        wprintf(L"Unable to allocate a connection handle\n");
        goto Exit;
    }

    // Connect to the data source
    ret = SQLDriverConnectA(hDbc, 
                           NULL, 
                           connectionString, 
                           SQL_NTS, 
                           NULL, 
                           0, 
                           NULL, 
                           SQL_DRIVER_NOPROMPT);
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        wprintf(L"Connection was successfully established!\n");
    } else {
        wprintf(L"Failed to open the connection.\n");
        goto Exit;
    }

    /*
    // Allocate a statement handle
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
    if (ret == SQL_SUCCESS) {
        // Define a SQL query
        SQLWCHAR query[] = L"SELECT DEPTNO, DNAME FROM DEPT";        

        // Execute the SQL query
        ret = SQLExecDirect(hStmt, query, SQL_NTS);
        if (ret == SQL_SUCCESS) {
            SQLWCHAR colData[256];
            SQLLEN colDataLen;

            // Fetch and display the results
            while (SQLFetch(hStmt) == SQL_SUCCESS) {
                SQLGetData(hStmt, 1, SQL_C_WCHAR, colData, sizeof(colData), &colDataLen);
                wprintf(L"Records: %s\n", colData);                
            }
        } else {
            wprintf(L"Failed to execute the query.\n");
            goto Exit;
        }
    }*/

Exit:
    // Free the statement handle
    if (hStmt) {
        SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    }

    if (hDbc) {
        // Close the connection
        SQLDisconnect(hDbc);
        wprintf(L"Connection was closed.\n");
        // Free the connection handle
        SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    }

    // Free the environment handle
    if (hEnv) {
        SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
    }

    return 0;
}