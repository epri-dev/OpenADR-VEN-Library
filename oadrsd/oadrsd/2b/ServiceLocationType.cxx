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

#include "ServiceLocationType.hxx"

#include "FeatureCollection.hxx"

namespace power
{
  // ServiceLocationType
  // 

  const ServiceLocationType::FeatureCollection_type& ServiceLocationType::
  FeatureCollection () const
  {
    return this->FeatureCollection_.get ();
  }

  ServiceLocationType::FeatureCollection_type& ServiceLocationType::
  FeatureCollection ()
  {
    return this->FeatureCollection_.get ();
  }

  void ServiceLocationType::
  FeatureCollection (const FeatureCollection_type& x)
  {
    this->FeatureCollection_.set (x);
  }

  void ServiceLocationType::
  FeatureCollection (::std::unique_ptr< FeatureCollection_type > x)
  {
    this->FeatureCollection_.set (std::move (x));
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

namespace power
{
  // ServiceLocationType
  //

  ServiceLocationType::
  ServiceLocationType (const FeatureCollection_type& FeatureCollection)
  : ::xml_schema::type (),
    FeatureCollection_ (FeatureCollection, this)
  {
  }

  ServiceLocationType::
  ServiceLocationType (::std::unique_ptr< FeatureCollection_type > FeatureCollection)
  : ::xml_schema::type (),
    FeatureCollection_ (std::move (FeatureCollection), this)
  {
  }

  ServiceLocationType::
  ServiceLocationType (const ServiceLocationType& x,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    FeatureCollection_ (x.FeatureCollection_, f, this)
  {
  }

  ServiceLocationType::
  ServiceLocationType (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    FeatureCollection_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void ServiceLocationType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // FeatureCollection
      //
      if (n.name () == "FeatureCollection" && n.namespace_ () == "http://www.opengis.net/gml/3.2")
      {
        ::std::unique_ptr< FeatureCollection_type > r (
          FeatureCollection_traits::create (i, f, this));

        if (!FeatureCollection_.present ())
        {
          this->FeatureCollection_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!FeatureCollection_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "FeatureCollection",
        "http://www.opengis.net/gml/3.2");
    }
  }

  ServiceLocationType* ServiceLocationType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class ServiceLocationType (*this, f, c);
  }

  ServiceLocationType& ServiceLocationType::
  operator= (const ServiceLocationType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->FeatureCollection_ = x.FeatureCollection_;
    }

    return *this;
  }

  ServiceLocationType::
  ~ServiceLocationType ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace power
{
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

namespace power
{
  void
  operator<< (::xercesc::DOMElement& e, const ServiceLocationType& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // FeatureCollection
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "FeatureCollection",
          "http://www.opengis.net/gml/3.2",
          e));

      s << i.FeatureCollection ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

