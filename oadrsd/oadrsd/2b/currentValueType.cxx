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

#include "currentValueType.hxx"

#include "PayloadFloatType.hxx"

namespace oadr2b
{
  namespace ei
  {
    // currentValueType
    // 

    const currentValueType::payloadFloat_type& currentValueType::
    payloadFloat () const
    {
      return this->payloadFloat_.get ();
    }

    currentValueType::payloadFloat_type& currentValueType::
    payloadFloat ()
    {
      return this->payloadFloat_.get ();
    }

    void currentValueType::
    payloadFloat (const payloadFloat_type& x)
    {
      this->payloadFloat_.set (x);
    }

    void currentValueType::
    payloadFloat (::std::unique_ptr< payloadFloat_type > x)
    {
      this->payloadFloat_.set (std::move (x));
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
  namespace ei
  {
    // currentValueType
    //

    currentValueType::
    currentValueType (const payloadFloat_type& payloadFloat)
    : ::xml_schema::type (),
      payloadFloat_ (payloadFloat, this)
    {
    }

    currentValueType::
    currentValueType (::std::unique_ptr< payloadFloat_type > payloadFloat)
    : ::xml_schema::type (),
      payloadFloat_ (std::move (payloadFloat), this)
    {
    }

    currentValueType::
    currentValueType (const currentValueType& x,
                      ::xml_schema::flags f,
                      ::xml_schema::container* c)
    : ::xml_schema::type (x, f, c),
      payloadFloat_ (x.payloadFloat_, f, this)
    {
    }

    currentValueType::
    currentValueType (const ::xercesc::DOMElement& e,
                      ::xml_schema::flags f,
                      ::xml_schema::container* c)
    : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
      payloadFloat_ (this)
    {
      if ((f & ::xml_schema::flags::base) == 0)
      {
        ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
        this->parse (p, f);
      }
    }

    void currentValueType::
    parse (::xsd::cxx::xml::dom::parser< char >& p,
           ::xml_schema::flags f)
    {
      for (; p.more_content (); p.next_content (false))
      {
        const ::xercesc::DOMElement& i (p.cur_element ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (i));

        // payloadFloat
        //
        {
          ::std::unique_ptr< ::xsd::cxx::tree::type > tmp (
            ::xsd::cxx::tree::type_factory_map_instance< 0, char > ().create (
              "payloadFloat",
              "http://docs.oasis-open.org/ns/energyinterop/201110",
              &::xsd::cxx::tree::factory_impl< payloadFloat_type >,
              true, true, i, n, f, this));

          if (tmp.get () != 0)
          {
            if (!payloadFloat_.present ())
            {
              ::std::unique_ptr< payloadFloat_type > r (
                dynamic_cast< payloadFloat_type* > (tmp.get ()));

              if (r.get ())
                tmp.release ();
              else
                throw ::xsd::cxx::tree::not_derived< char > ();

              this->payloadFloat_.set (::std::move (r));
              continue;
            }
          }
        }

        break;
      }

      if (!payloadFloat_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "payloadFloat",
          "http://docs.oasis-open.org/ns/energyinterop/201110");
      }
    }

    currentValueType* currentValueType::
    _clone (::xml_schema::flags f,
            ::xml_schema::container* c) const
    {
      return new class currentValueType (*this, f, c);
    }

    currentValueType& currentValueType::
    operator= (const currentValueType& x)
    {
      if (this != &x)
      {
        static_cast< ::xml_schema::type& > (*this) = x;
        this->payloadFloat_ = x.payloadFloat_;
      }

      return *this;
    }

    currentValueType::
    ~currentValueType ()
    {
    }
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace oadr2b
{
  namespace ei
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
  namespace ei
  {
    void
    operator<< (::xercesc::DOMElement& e, const currentValueType& i)
    {
      e << static_cast< const ::xml_schema::type& > (i);

      // payloadFloat
      //
      {
        ::xsd::cxx::tree::type_serializer_map< char >& tsm (
          ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ());

        const currentValueType::payloadFloat_type& x (i.payloadFloat ());
        if (typeid (currentValueType::payloadFloat_type) == typeid (x))
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "payloadFloat",
              "http://docs.oasis-open.org/ns/energyinterop/201110",
              e));

          s << x;
        }
        else
          tsm.serialize (
            "payloadFloat",
            "http://docs.oasis-open.org/ns/energyinterop/201110",
            true, true, e, x);
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

