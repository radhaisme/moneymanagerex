// -*- C++ -*-
//=============================================================================
/**
 *      Copyright (c) 2013 Guan Lisheng (guanlisheng@gmail.com)
 *
 *      @file
 *
 *      @author [sqlite2cpp.py]
 *
 *      @brief
 *
 *      Revision History:
 *          AUTO GENERATED at 2013-10-23 11:32:46.576643.
 *          DO NOT EDIT!
 */
//=============================================================================

#ifndef DB_TABLE_SUBCATEGORY_V1_H
#define DB_TABLE_SUBCATEGORY_V1_H

#include "DB_Table.h"

struct DB_Table_SUBCATEGORY_V1 : public DB_Table
{
    struct Data;
    typedef DB_Table_SUBCATEGORY_V1 Self;
    typedef std::vector<Self::Data> Data_Set;
    typedef std::vector<Self::Data*> Cache;
    Cache cache_;
    ~DB_Table_SUBCATEGORY_V1() 
    {
        std::for_each(cache_.begin(), cache_.end(), std::mem_fun(&Data::destroy));
    }

    bool ensure(wxSQLite3Database* db) const
    {
        if (exists(db)) return true;

        try
        {
            db->ExecuteUpdate("CREATE TABLE SUBCATEGORY_V1(SUBCATEGID integer primary key, SUBCATEGNAME TEXT COLLATE NOCASE NOT NULL, CATEGID integer NOT NULL, UNIQUE(CATEGID, SUBCATEGNAME))");
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("SUBCATEGORY_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    struct SUBCATEGID : public DB_Column<int>
    { 
        static wxString name() { return "SUBCATEGID"; } 
        SUBCATEGID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct SUBCATEGNAME : public DB_Column<wxString>
    { 
        static wxString name() { return "SUBCATEGNAME"; } 
        SUBCATEGNAME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct CATEGID : public DB_Column<int>
    { 
        static wxString name() { return "CATEGID"; } 
        CATEGID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    typedef SUBCATEGID PRIMARY;
    enum COLUMN
    {
        COL_SUBCATEGID = 0
        , COL_SUBCATEGNAME = 1
        , COL_CATEGID = 2
    };

    wxString column_to_name(COLUMN col) const
    {
        switch(col)
        {
            case COL_SUBCATEGID: return "SUBCATEGID";
            case COL_SUBCATEGNAME: return "SUBCATEGNAME";
            case COL_CATEGID: return "CATEGID";
            default: break;
        }
        
        return "UNKNOWN";
    }

    COLUMN name_to_column(const wxString& name) const
    {
        if ("SUBCATEGID" == name) return COL_SUBCATEGID;
        else if ("SUBCATEGNAME" == name) return COL_SUBCATEGNAME;
        else if ("CATEGID" == name) return COL_CATEGID;

        return COLUMN(-1);
    }
    
    struct Data
    {
        friend struct DB_Table_SUBCATEGORY_V1;
        Self* view_;
    
        int SUBCATEGID;//  primay key
        wxString SUBCATEGNAME;
        int CATEGID;
        int id() const { return SUBCATEGID; }
        void id(int id) { SUBCATEGID = id; }
        bool operator < (const Data& r) const
        {
            return this->id() < r.id();
        }
        bool operator < (const Data* r) const
        {
            return this->id() < r->id();
        }

        Data(Self* view) 
        {
            view_ = view;
        
            SUBCATEGID = -1;
            CATEGID = -1;
        }

        Data(wxSQLite3ResultSet& q, Self* view = 0)
        {
            view_ = view;
        
            SUBCATEGID = q.GetInt("SUBCATEGID");
            SUBCATEGNAME = q.GetString("SUBCATEGNAME");
            CATEGID = q.GetInt("CATEGID");
        }

        wxString to_json() const
        {
            json::Object o;
            this->to_json(o);
            std::stringstream ss;
            json::Writer::Write(o, ss);
            return ss.str();
        }
        int to_json(json::Object& o) const
        {
            o["SUBCATEGID"] = json::Number(this->SUBCATEGID);
            o["SUBCATEGNAME"] = json::String(this->SUBCATEGNAME.ToStdString());
            o["CATEGID"] = json::Number(this->CATEGID);
            return 0;
        }
        bool save(wxSQLite3Database* db)
        {
            if (!view_ || !db) 
            {
                wxLogError("can not save");
                return false;
            }

            return view_->save(this, db);
        }

        bool remove(wxSQLite3Database* db)
        {
            if (!view_ || !db) 
            {
                wxLogError("can not remove");
                return false;
            }
            
            return view_->remove(this, db);
        }

        void destroy() { delete this; }
    };

    enum
    {
        NUM_COLUMNS = 3
    };

    size_t num_columns() const { return NUM_COLUMNS; }

    struct SorterBySUBCATEGID
    { 
        bool operator()(const Data& x, const Data& y)
        {
            return x.SUBCATEGID < y.SUBCATEGID;
        }
    };
    struct SorterBySUBCATEGNAME
    { 
        bool operator()(const Data& x, const Data& y)
        {
            return x.SUBCATEGNAME < y.SUBCATEGNAME;
        }
    };
    struct SorterByCATEGID
    { 
        bool operator()(const Data& x, const Data& y)
        {
            return x.CATEGID < y.CATEGID;
        }
    };
    wxString name() const { return "SUBCATEGORY_V1"; }

    DB_Table_SUBCATEGORY_V1() 
    {
        query_ = "SELECT SUBCATEGID, SUBCATEGNAME, CATEGID FROM SUBCATEGORY_V1 ";
    }

    Self::Data* create()
    {
        Self::Data* entity = new Self::Data(this);
        cache_.push_back(entity);
        return entity;
    }
    Self::Data* clone(const Data* e)
    {
        Self::Data* entity = create();
        *entity = *e;
        entity->id(-1);
        return entity;
    }

    bool save(Self::Data* entity, wxSQLite3Database* db)
    {
        wxString sql = wxEmptyString;
        if (entity->id() < 0) //  new & insert
        {
            sql = "INSERT INTO SUBCATEGORY_V1(SUBCATEGNAME, CATEGID) VALUES(?, ?)";
        }
        else
        {
            sql = "UPDATE SUBCATEGORY_V1 SET SUBCATEGNAME = ?, CATEGID = ? WHERE SUBCATEGID = ?";
        }

        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(sql);

            stmt.Bind(1, entity->SUBCATEGNAME);
            stmt.Bind(2, entity->CATEGID);
            if (entity->id() > 0)
                stmt.Bind(3, entity->SUBCATEGID);

            wxLogDebug(stmt.GetSQL());
            stmt.ExecuteUpdate();
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("SUBCATEGORY_V1: Exception %s, %s", e.GetMessage().c_str(), entity->to_json());
            return false;
        }

        if (entity->id() < 0) entity->id((db->GetLastRowId()).ToLong());
        return true;
    }

    bool remove(int id, wxSQLite3Database* db)
    {
        try
        {
            wxString sql = "DELETE FROM SUBCATEGORY_V1 WHERE SUBCATEGID = ?";
            wxSQLite3Statement stmt = db->PrepareStatement(sql);
            stmt.Bind(1, id);
            wxLogDebug(stmt.GetSQL());
            stmt.ExecuteUpdate();
            stmt.Finalize();

            Cache c;
            for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
            {
                Self::Data* entity = *it;
                if (entity->id() == id) 
                    delete entity;
                else 
                    c.push_back(entity);
            }
            cache_.clear();
            cache_.swap(c);
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("SUBCATEGORY_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    bool remove(Self::Data* entity, wxSQLite3Database* db)
    {
        if (remove(entity->id(), db))
        {
            entity->id(-1);
            return true;
        }

        return false;
    }

    
    Self::Data* get(int id, wxSQLite3Database* db)
    {
        if (id < 0) 
        {
            ++ skip_;
            wxLogDebug("%s :%d SKIP (hit %ld, miss %ld, skip %ld)", this->name(), id, this->hit_, this->miss_, this->skip_);
            return 0;
        }
        for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
        {
            Self::Data* entity = *it;
            if (entity->id() == id) 
            {
                ++ hit_;
                wxLogDebug("%s :%d HIT (hit %ld, miss %ld, skip %ld)", this->name(), id, this->hit_, this->miss_, this->skip_);
                return entity;
            }
        }
        
        ++ miss_;
        wxLogDebug("%s :%d MISS (hit %ld, miss %ld, skip %ld)", this->name(), id, this->hit_, this->miss_, this->skip_);
        Self::Data* entity = 0;
        wxString where = wxString::Format(" WHERE %s = ?", PRIMARY::name().c_str());
        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(this->query() + where);
            stmt.Bind(1, id);

            wxLogDebug(stmt.GetSQL());
            wxSQLite3ResultSet q = stmt.ExecuteQuery();
            if(q.NextRow())
            {
                entity = new Self::Data(q, this);
                cache_.push_back(entity);
            }
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }
        
        if (!entity) 
        {
            wxLogError("%s: %d not found", this->name().c_str(), id);
        }
 
        return entity;
    }

    Data_Set all(wxSQLite3Database* db, COLUMN col = COLUMN(0), bool asc = true)
    {
        Data_Set result;
        try
        {
            wxSQLite3ResultSet q = db->ExecuteQuery(this->query() + " ORDER BY " + column_to_name(col) + " COLLATE NOCASE " + (asc ? " ASC " : " DESC ")
                + "," + PRIMARY::name());

            wxLogDebug(q.GetSQL());
            while(q.NextRow())
            {
                Self::Data entity(q, this);
                result.push_back(entity);
            }

            q.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }

        return result;
    }

};
#endif //
