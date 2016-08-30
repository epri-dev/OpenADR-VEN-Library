// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "CanonicalizationMethodType.hxx"

namespace oadr2b
{
  namespace sig
  {
    // CanonicalizationMethodType
    // 

    const CanonicalizationMethodType::Algorithm_type& CanonicalizationMethodType::
    Algorithm () const
    {
      return this->Algorithm_.get ();
    }

    CanonicalizationMethodType::Algorithm_type& CanonicalizationMethodType::
    Algorithm ()
    {
      return this->Algorithm_.get ();
    }

    void CanonicalizationMethodType::
    Algorithm (const Algorithm_type& x)
    {
      this->Algorithm_.set (x);
    }

    void CanonicalizationMethodType::
    Algorithm (::std::unique_ptr< Algorithm_type > x)
    {
      this->Algorithm_.set (std::move (x));
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

#include <xsd/cxx/tree/type-factory-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_factory_plate< 0, char >
  type_factory_plate_init;
}

namespace oadr2b
{
  namespace sig
  {
    // CanonicalizationMethodType
    //

    CanonicalizationMethodType::
    CanonicalizationMethodType (const Algorithm_type& Algorithm)
    : ::xml_schema::type (),
      Algorithm_ (Algorithm, this)
    {
    }

    CanonicalizationMethodType::
    CanonicalizationMethodType (const CanonicalizationMethodType& x,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
    : ::xml_schema::type (x, f, c),
      Algorithm_ (x.Algorithm_, f, this)
    {
    }

    CanonicalizationMethodType::
    CanonicalizationMethodType (const ::xercesc::DOMElement& e,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
    : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
      Algorithm_ (this)
    {
      if ((f & ::xml_schema::flags::base) == 0)
      {
        ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
        this->parse (p, f);
      }
    }

    void CanonicalizationMethodType::
    parse (::xsd::cxx::xml::dom::parser< char >& p,
           ::xml_schema::flags f)
    {
      for (; p.more_content (); p.next_content (false))
      {
        const ::xercesc::DOMElement& i (p.cur_element ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (i));

        break;
      }

      while (p.more_attributes ())
      {
        const ::xercesc::DOMAttr& i (p.next_attribute ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (i));

        if (n.name () == "Algorithm" && n.namespace_ ().empty ())
        {
          this->Algorithm_.set (Algorithm_traits::create (i, f, this));
          continue;
        }
      }

      if (!Algorithm_.present ())
      {
        throw ::xsd::cxx::tree::expected_attribute< char > (
          "Algorithm",
          "");
      }
    }

    CanonicalizationMethodType* CanonicalizationMethodType::
    _clone (::xml_schema::flags f,
            ::xml_schema::container* c) const
    {
      return new class CanonicalizationMethodType (*this, f, c);
    }

    CanonicalizationMethodType& CanonicalizationMethodType::
    operator= (const CanonicalizationMethodType& x)
    {
      if (this != &x)
      {
        static_cast< ::xml_schema::type& > (*this) = x;
        this->Algorithm_ = x.Algorithm_;
      }

      return *this;
    }

    CanonicalizationMethodType::
    ~CanonicalizationMethodType ()
    {
    }
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace oadr2b
{
  namespace sig
  {
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

#include <xsd/cxx/tree/type-serializer-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_serializer_plate< 0, char >
  type_serializer_plate_init;
}

namespace oadr2b
{
  namespace sig
  {
    void
    operator<< (::xercesc::DOMElement& e, const CanonicalizationMethodType& i)
    {
      e << static_cast< const ::xml_schema::type& > (i);

      // Algorithm
      //
      {
        ::xercesc::DOMAttr& a (
          ::xsd::cxx::xml::dom::create_attribute (
            "Algorithm",
            e));

        a << i.Algorithm ();
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

