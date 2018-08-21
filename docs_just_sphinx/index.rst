Testing With Just Sphinx
========================

.. toctree::
   :maxdepth: 2

   manual_sphinx

Link Testing
============

Traditional Links
-----------------

Old way of linking always works:

- ``simgrid::s4u::Actor::kill`` links correctly: :cpp:func:`simgrid::s4u::Actor::kill`

New Overload Links for Sphinx v1.8
----------------------------------

Explicit Overload v1
++++++++++++++++++++

- ``void simgrid::s4u::Actor::kill()``: :cpp:func:`void simgrid::s4u::Actor::kill()`

Always works.

Explicit Overload v2
++++++++++++++++++++

- ``void simgrid::s4u::Actor::kill(aid_t)``: :cpp:func:`void simgrid::s4u::Actor::kill(aid_t)`

Always works.
