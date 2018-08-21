Testing With Breathe
====================

.. toctree::
   :maxdepth: 2

   api_documentation

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

Unlike the Exhale example, this one always works.

Explicit Overload v2
++++++++++++++++++++

- ``void simgrid::s4u::Actor::kill(aid_t)``: :cpp:func:`void simgrid::s4u::Actor::kill(aid_t)`

Every other build will fail on this.

1. Run ``make html`` once, and it will succeed.
2. Run ``make html`` again, without changing anything, and it will fail:

.. code-block:: py3tb

     File "/home/sven/Desktop/sphinx-cpp-cross-ref-bug/docs_breathe/venv/lib/python2.7/site-packages/sphinx/domains/cpp.py", line 4170, in find_declaration
       candId = symbol.declaration.get_newest_id()
   AttributeError: 'NoneType' object has no attribute 'get_newest_id'

The full log for this specific error:

.. literalinclude:: sphinx-err-vYbvDs.log
   :language: none
